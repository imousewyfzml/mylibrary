package de.kp.rtspcamera;


import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileNotFoundException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.nio.ByteBuffer;
import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.NoSuchElementException ;
import android.os.SystemProperties;


import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Matrix;
import android.media.ExifInterface;
import android.hardware.Camera;
import android.media.MediaCodec;
import android.media.MediaFormat;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.Message;
import android.hardware.Camera.Parameters;
import android.hardware.Camera.Size ;
import android.util.Log;
import android.media.MediaMuxer;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnCompletionListener;
import android.media.MediaPlayer.OnErrorListener;
import android.graphics.SurfaceTexture;
//import com.android.camera.RecorderThread ;
import android.graphics.Canvas;
import android.graphics.Rect;
import android.view.SurfaceHolder;
import android.view.Surface ;
import android.graphics.SurfaceTexture;
import android.opengl.GLES20;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;


class CameraMediaCodec extends HandlerThread implements MediaPlayer.OnErrorListener, MediaPlayer.OnCompletionListener,Camera.PreviewCallback {
    private static final String LOG_TAG = "cameraMediaCodec";
    private static final boolean VDBG = true ;

    private static final int DEQUEQUE_TIMEOUT = 30*1000; //modify 1000 to 30*1000 according enc lentancy
    private static final int MAX_FRAME_COUNT = 3;
    public static final int VIDEO_TYPE_H263 = 1;
    public static final int VIDEO_TYPE_H264 = 2;
    public static final int VIDEO_TYPE_MPEG4 =3 ;
    private static final int MSG_CAMERA_START = 1;

    private MediaPlayer mMediaPlayer = null;
	
    private static  int BUFFER_SIZE  ;//176*144*1.5;
    private static final boolean DUMP_CAMERA = false;

    Handler mHandler;
    private Camera mCamera;
    private Parameters mParameters;
    private String mCodecFilename ;

    private volatile  boolean m_bStarted = false;
    private Object m_GetBuffer = new Object();
    private Object m_StopLock = new Object();
    private Object m_CameraLock = new Object();
   // Object m_pipeLock = new Object();
    private Thread mWorkThread = null;
    private Thread mPlayThread = null;

    private int m_iframe = 0;
    private int m_nNum = 0;
    private int m_nDataStart = 0;
    private int m_nDataEnd = 0;
    private int m_videohight = 1080; ;
    private int m_videoWeight = 1920 ;
    private int m_key_color_format  =21;

    private Queue<ByteBuffer> m_RingBuffer = new ConcurrentLinkedQueue<ByteBuffer>();

    private int mVideoType = VIDEO_TYPE_H264;

    private long m_presentationTimeUs = 0;
    private Object m_seqLock = new Object() ;
    private Bitmap mBitmapSrc = null;
    // native fields
    private   MediaMuxer muxer;
    private RecorderThread audiorecorder;

   public static final boolean   DEBUG_YUV422 = false ;
   public static final boolean   DEBUG_YVU = false ;
   
   public static final boolean   ROTE_YUV =  false  ;
   public static final boolean   DEBUG_ACODEC_RECORD = true ;
   public static final boolean   DEBUG_NATIVE_RECORD = false  ;
   public static final boolean   DEBUG_ACODEC_WRITE = false  ;
   public static final boolean   DEBUG_ACODEC_PLAYER = false  ;
   
   public Surface mSurface = null;
   private SurfaceTexture mSurfaceTexture = null;
   private int mTextureID;
   
    private static final int GL_TEXTURE_EXTERNAL_OES = 0x8D65;
    private static final int FLOAT_SIZE_BYTES = 4;
    private static final int VERTICES_DATA_STRIDE_BYTES = 5 * FLOAT_SIZE_BYTES;
    private static final int VERTICES_DATA_POS_OFFSET = 0;
    private static final int VERTICES_DATA_UV_OFFSET = 3;
    private  fakeSurfaceHolder   fakeSurface = null;
    private SurfaceHolder  mPlayerRender = null ;

    private OutputStream  mStreamOut = null ;

   private class fakeSurfaceHolder  implements SurfaceHolder 
   {

      public void addCallback(Callback callback){}

    /**
     * Removes a previously added Callback interface from this holder.
     * 
     * @param callback The Callback interface to remove.
     */
    public void removeCallback(Callback callback){}

    /**
     * Use this method to find out if the surface is in the process of being
     * created from Callback methods. This is intended to be used with
     * {@link Callback#surfaceChanged}.
     * 
     * @return true if the surface is in the process of being created.
     */
    public boolean isCreating(){return true;}
    
    /**
     * Sets the surface's type.
     *  
     * @deprecated this is ignored, this value is set automatically when needed.
     */
    @Deprecated
    public void setType(int type){}

    /**
     * Make the surface a fixed size.  It will never change from this size.
     * When working with a {@link SurfaceView}, this must be called from the
     * same thread running the SurfaceView's window.
     * 
     * @param width The surface's width.
     * @param height The surface's height.
     */
    public void setFixedSize(int width, int height){}

    /**
     * Allow the surface to resized based on layout of its container (this is
     * the default).  When this is enabled, you should monitor
     * {@link Callback#surfaceChanged} for changes to the size of the surface.
     * When working with a {@link SurfaceView}, this must be called from the
     * same thread running the SurfaceView's window.
     */
    public void setSizeFromLayout(){}

    /**
     * Set the desired PixelFormat of the surface.  The default is OPAQUE.
     * When working with a {@link SurfaceView}, this must be called from the
     * same thread running the SurfaceView's window.
     * 
     * @param format A constant from PixelFormat.
     * 
     * @see android.graphics.PixelFormat
     */
    public void setFormat(int format){}

    /**
     * Enable or disable option to keep the screen turned on while this
     * surface is displayed.  The default is false, allowing it to turn off.
     * This is safe to call from any thread.
     * 
     * @param screenOn Set to true to force the screen to stay on, false
     * to allow it to turn off.
     */
    public void setKeepScreenOn(boolean screenOn){}
    
    /**
     * Start editing the pixels in the surface.  The returned Canvas can be used
     * to draw into the surface's bitmap.  A null is returned if the surface has
     * not been created or otherwise cannot be edited.  You will usually need
     * to implement {@link Callback#surfaceCreated Callback.surfaceCreated}
     * to find out when the Surface is available for use.
     * 
     * <p>The content of the Surface is never preserved between unlockCanvas() and
     * lockCanvas(), for this reason, every pixel within the Surface area
     * must be written. The only exception to this rule is when a dirty
     * rectangle is specified, in which case, non-dirty pixels will be
     * preserved.
     * 
     * <p>If you call this repeatedly when the Surface is not ready (before
     * {@link Callback#surfaceCreated Callback.surfaceCreated} or after
     * {@link Callback#surfaceDestroyed Callback.surfaceDestroyed}), your calls
     * will be throttled to a slow rate in order to avoid consuming CPU.
     * 
     * <p>If null is not returned, this function internally holds a lock until
     * the corresponding {@link #unlockCanvasAndPost} call, preventing
     * {@link SurfaceView} from creating, destroying, or modifying the surface
     * while it is being drawn.  This can be more convenient than accessing
     * the Surface directly, as you do not need to do special synchronization
     * with a drawing thread in {@link Callback#surfaceDestroyed
     * Callback.surfaceDestroyed}.
     * 
     * @return Canvas Use to draw into the surface.
     */
    public Canvas lockCanvas(){return null;}

    
    /**
     * Just like {@link #lockCanvas()} but allows specification of a dirty rectangle.
     * Every
     * pixel within that rectangle must be written; however pixels outside
     * the dirty rectangle will be preserved by the next call to lockCanvas().
     * 
     * @see android.view.SurfaceHolder#lockCanvas
     * 
     * @param dirty Area of the Surface that will be modified.
     * @return Canvas Use to draw into the surface.
     */
    public Canvas lockCanvas(Rect dirty){return null ;}

    /**
     * Finish editing pixels in the surface.  After this call, the surface's
     * current pixels will be shown on the screen, but its content is lost,
     * in particular there is no guarantee that the content of the Surface
     * will remain unchanged when lockCanvas() is called again.
     * 
     * @see #lockCanvas()
     *
     * @param canvas The Canvas previously returned by lockCanvas().
     */
    public void unlockCanvasAndPost(Canvas canvas){}

    /**
     * Retrieve the current size of the surface.  Note: do not modify the
     * returned Rect.  This is only safe to call from the thread of
     * {@link SurfaceView}'s window, or while inside of
     * {@link #lockCanvas()}.
     * 
     * @return Rect The surface's dimensions.  The left and top are always 0.
     */
    public Rect getSurfaceFrame(){return null;}

    /**
     * Direct access to the surface object.  The Surface may not always be
     * available -- for example when using a {@link SurfaceView} the holder's
     * Surface is not created until the view has been attached to the window
     * manager and performed a layout in order to determine the dimensions
     * and screen position of the Surface.    You will thus usually need
     * to implement {@link Callback#surfaceCreated Callback.surfaceCreated}
     * to find out when the Surface is available for use.
     * 
     * <p>Note that if you directly access the Surface from another thread,
     * it is critical that you correctly implement
     * {@link Callback#surfaceCreated Callback.surfaceCreated} and
     * {@link Callback#surfaceDestroyed Callback.surfaceDestroyed} to ensure
     * that thread only accesses the Surface while it is valid, and that the
     * Surface does not get destroyed while the thread is using it.
     * 
     * <p>This method is intended to be used by frameworks which often need
     * direct access to the Surface object (usually to pass it to native code).
     * 
     * @return Surface The surface.
     */
    public Surface getSurface(){return mSurface;}
   	
   }


   private void initSurfaceText()
   {
        log("initSurfaceText");
        int[] textures = new int[1];
         GLES20.glGenTextures(1, textures, 0);

        mTextureID = textures[0];
        GLES20.glBindTexture(GL_TEXTURE_EXTERNAL_OES, mTextureID);
      
        GLES20.glTexParameterf(GL_TEXTURE_EXTERNAL_OES, GLES20.GL_TEXTURE_MIN_FILTER,
                GLES20.GL_NEAREST);
        GLES20.glTexParameterf(GL_TEXTURE_EXTERNAL_OES, GLES20.GL_TEXTURE_MAG_FILTER,
                GLES20.GL_LINEAR);
        // Clamp to edge is the only option
        GLES20.glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GLES20.GL_TEXTURE_WRAP_S,
                GLES20.GL_CLAMP_TO_EDGE);
        GLES20.glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GLES20.GL_TEXTURE_WRAP_T,
                GLES20.GL_CLAMP_TO_EDGE);
 
        if (mSurfaceTexture != null) {
            mSurfaceTexture.release();
        }
        mSurfaceTexture = new SurfaceTexture(mTextureID);
        mSurface = new Surface(mSurfaceTexture);
   }


       // Below are notifications from VideoView
    @Override
    public boolean onError(MediaPlayer player, int arg1, int arg2) {
        /*<DTS2013010601955 huangbangbang/00191767 20130106 begin */
	        log("playmedia() onError");
	        internalStartPlay(mPlayerRender);
		return true ;
  
     }

    @Override
    public void onCompletion(MediaPlayer mp) {
             log("playmedia() onCompletion");
             internalStartPlay(mPlayerRender);
    }
    public SurfaceHolder getfakeSurface() {
      
	     if(fakeSurface == null)
	     {
	      	initSurfaceText();
	     }
	    fakeSurface =   new fakeSurfaceHolder() ;
	     log("playmedia() getfakeSurface" +fakeSurface );
	     return fakeSurface ;
    }
	
  private void playmedia()
  {
    	//String  uriString = "rtsp://192.168.42.149:8554/test";
    	String  uriString = SystemProperties.get("camere.media.testrtsp", "null") ;
    	if(uriString.equals("null"))
    	{
    	      log("start playmedia() not set uri, not play");
	      return ;
    	}
	
        if(mMediaPlayer !=null)
        {
           mMediaPlayer.stop();
           mMediaPlayer.release();
        }
	try{
        mMediaPlayer = new MediaPlayer();
        mMediaPlayer.setOnCompletionListener(CameraMediaCodec.this);
        mMediaPlayer.setOnErrorListener(CameraMediaCodec.this);
        mMediaPlayer.setDataSource(uriString);
        mMediaPlayer.setDisplay(mPlayerRender);
        mMediaPlayer.setAudioStreamType(3);//AudioManager.STREAM_MUSIC
        mMediaPlayer.setScreenOnWhilePlaying(true);
        mMediaPlayer.prepare();
	}catch(java.io.IOException exp)
	{
	        log("playmedia() exp");
	}
        log("start playmedia()");
        mMediaPlayer.start() ;

  }
   private void log(String msg) {
        Log.d(LOG_TAG, msg);
    }

    private static void vlog(String msg) {
        Log.d(LOG_TAG, msg);
    }

    CameraMediaCodec(String name, OutputStream  streamout , Parameters Para) {
        super("CameraMediaCodec");
	mParameters = Para;
	if(Para == null)
	{
		return ;
	}
	mCodecFilename = name ;
	mStreamOut = streamout ;
	int rotation = 0;
	if (ROTE_YUV)
	{
	   rotation = mParameters.getInt("rotation");
	}
	
	Size  previewSize = mParameters.getPreviewSize();
	if(rotation == 90 ||rotation == 270 )
	{
		m_videoWeight = previewSize.height;
		m_videohight  = previewSize.width;
	}
	else
	{
		m_videoWeight = previewSize.width;
		m_videohight  =  previewSize.height;
	}
	String previewformat = mParameters.get("preview-format");
	if( previewformat.equals("yuv422i-yuyv") ||previewformat.equals("yvu420sp"))
	{
	    BUFFER_SIZE = m_videoWeight *m_videohight *2 ; 
	    m_key_color_format =   25;       //OMX_COLOR_FormatYUV422SemiPlanar, 39, 2130706437,2130706433
	}
	else
	{
	       BUFFER_SIZE = m_videoWeight *m_videohight *3/2;
	       m_key_color_format =   0x7F000002;// 0x7F000002,0x7F000005
	}
        log("rotation: " + rotation+ ":m_videohight:" +m_videohight +":m_videoWeight:" + m_videoWeight+ ":previewformat:" +previewformat+":m_key_color_format:"+ m_key_color_format + "filename" +name );
    }

    void setCamera(Camera cam){
        log("setCamera() E, " + cam);
        synchronized (m_CameraLock) {
            mCamera = cam;
        }
        log("setCamera() X");
    }
    void enablePreviewCallback(boolean enable){
        log("enablePreviewCallback, " + enable);
        synchronized (m_CameraLock) {
            if(mCamera == null)
            return ;
            if(enable)
            {
                byte[]  buffer1 = new byte[BUFFER_SIZE]  ;
                byte[]  buffer2 = new byte[BUFFER_SIZE]  ;
                byte[]  buffer3 = new byte[BUFFER_SIZE]  ;
	    //    byte[]  buffer4 = new byte[BUFFER_SIZE]  ;
		
                if (mCamera != null) {
                     mCamera.setPreviewCallbackWithBuffer(CameraMediaCodec.this);
                     mCamera.addCallbackBuffer(buffer1);
                     mCamera.addCallbackBuffer(buffer2);
                     mCamera.addCallbackBuffer(buffer3);
		//     mCamera.addCallbackBuffer(buffer4);
	         }
            }
            else
            {
                mCamera.setPreviewCallbackWithBuffer(null);
            }
        }
        log("enablePreviewCallback");
    }
    void startWork() {
       synchronized(m_seqLock){
        if(mHandler == null)
        {
           log("mHandler == null wait HandlerThread start");
           synchronized(m_StopLock) {
           start();
           try {
                  m_StopLock.wait();
              } catch (InterruptedException e) {
                  e.printStackTrace();
              }
          }
        }
        synchronized(m_StopLock) {
          mHandler.sendEmptyMessage(MSG_CAMERA_START);
           try {
                  m_StopLock.wait();
              } catch (InterruptedException e) {
                  e.printStackTrace();
              }
          }
        }
	if(DEBUG_ACODEC_RECORD)
	{
         audiorecorder = new  RecorderThread("audioRecoder",1);
         audiorecorder.enableRecord(true,1,null) ;
	}
    }

    void stopWork() {
        log("stopWork() E");
        synchronized(m_seqLock){
        if (m_bStarted) {         
            synchronized(m_StopLock) {
            m_bStarted = false;
            synchronized (m_CameraLock) {
                if (mCamera != null) {
                    mCamera.setPreviewCallbackWithBuffer(null);
                }
            }
            synchronized(m_GetBuffer) {
                m_GetBuffer.notify();
            }
         try {
                    m_StopLock.wait();
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
        }
       }
        if(mMediaPlayer !=null)
        {
           mMediaPlayer.stop();
           mMediaPlayer.release();
	   mMediaPlayer =null ;
        }
	if(DEBUG_ACODEC_RECORD)
	{
	   audiorecorder.ExitRecord(1) ;
	}
        log("stopWork() X");
    }

    void setEncodeType(int type){
        log("setEncodeType() type: " + type);
        mVideoType = type;
    }

    protected void onLooperPrepared() {
        mHandler = new Handler(CameraMediaCodec.this.getLooper()) {
        @Override
        public void handleMessage(Message msg) {
            switch(msg.what) {
                case MSG_CAMERA_START:
                    log("handleMessage() MSG_UPLINK_START, UpLink.this: " + CameraMediaCodec.this);
                    boolean  preStarted = false ;
                    synchronized(m_StopLock) {
                    preStarted = m_bStarted ;
                        m_bStarted = true;
                        m_StopLock.notify();
                    }
                   if(preStarted)
                   {
                      log("prestarted so return");
                      return ;
                   }
	           internalStartEncode();
                   break;
               }
        }
      };
      synchronized(m_StopLock) {
                m_StopLock.notify();
       }
   }
    public  void internalStartPlay(SurfaceHolder Render) {
	mPlayerRender =  Render ;
        Runnable mainRun = new Runnable() {
            public void run(){
                playmedia();
	   }
      };
       mPlayThread = new Thread(mainRun);
        mPlayThread.start();
 }
	
    private void internalStartEncode() {

        Runnable mainRun = new Runnable() {
            public void run(){
                android.os.Process.setThreadPriority(android.os.Process.THREAD_PRIORITY_URGENT_AUDIO);
                log("internalStartEncode() E");
                MediaCodec codec;
                String typeStr = "video/3gpp";
                if (mVideoType == VIDEO_TYPE_MPEG4) {
                    typeStr = "video/mp4v-es";
                }
		else if(mVideoType == VIDEO_TYPE_H264)
		{
		     typeStr = "video/avc";
		}
                codec = MediaCodec.createEncoderByType(typeStr);
                MediaFormat format = new MediaFormat();
                format.setString(MediaFormat.KEY_MIME, typeStr);
                format.setInteger(MediaFormat.KEY_WIDTH, m_videoWeight);
                format.setInteger(MediaFormat.KEY_HEIGHT, m_videohight);
                format.setInteger(MediaFormat.KEY_BIT_RATE, 448000);
                format.setInteger(MediaFormat.KEY_COLOR_FORMAT, m_key_color_format);//OMX_COLOR_FormatYUV420SemiPlanar OMX_COLOR_FormatYUV422Planar
                format.setInteger(MediaFormat.KEY_FRAME_RATE, 30);
                format.setInteger(MediaFormat.KEY_I_FRAME_INTERVAL, 1);
                log("internalStartEncode() configure");
                codec.configure(format, null, null, MediaCodec.CONFIGURE_FLAG_ENCODE);
                log("internalStartEncode() start");
                codec.start();
                log("internalStartEncode() getInputBuffers");
                ByteBuffer[] inputBuffers = codec.getInputBuffers();
                ByteBuffer[] outputBuffers = codec.getOutputBuffers();
                //format = codec.getOutputFormat();
                OutputStream out = null;
                FileOutputStream fo= null;
                String vpatch = "/data/camera.mp4" ;
                log("MSG_UPLINK_START m_bStarted: " + m_bStarted + ":vpatch: " +vpatch);
                //OutputStream outFn = null;
              /*  
                try {
                    fo = new FileOutputStream(vpatch) ;
                    out = new BufferedOutputStream(fo);
                    //outFn = new BufferedOutputStream(new FileOutputStream("/data/vpout"));
                } catch (FileNotFoundException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
                */
                // for flow-control of MSG_CAMERA_START
                int inputBufferIndex = -1 ;
                int outputBufferIndex = -1 ;
                for(;;){
                    if (!m_bStarted){
                        break;
                    }
                    try {
                          inputBufferIndex = codec.dequeueInputBuffer(DEQUEQUE_TIMEOUT);
                    }catch (IllegalStateException e) {
                         e.printStackTrace();
                         if (!m_bStarted){
                             break;
                         }
                         format = codec.getOutputFormat();
                         continue;
                    }
                    vlog("internalStartEncode(), dequeueInputBuffer: " + inputBufferIndex);
                     if (inputBufferIndex >= 0) {    
                        int nSize = 0 ;
                        nSize  = m_RingBuffer.size();
                        vlog("internalStartEncode(), m_RingBuffer.size(): " + nSize);
                        if (nSize <= 0) {
                           synchronized(m_GetBuffer) {
                               try {
                                   m_GetBuffer.wait();
                               } catch (InterruptedException e) {
                               // TODO Auto-generated catch block
                                   e.printStackTrace();
                               }
                            }
                        }
                      ByteBuffer srcBuffer =null ;
                      try{
                          synchronized(m_GetBuffer) {
                              srcBuffer = m_RingBuffer.remove();
                          }
                      }
                      catch (NoSuchElementException e)
                      {
                          e.printStackTrace();
                          continue;
                      }
                        vlog("VT_TS Up internalStartEncode(), srcBuffer.size(): " + srcBuffer.array().length);
                        inputBuffers[inputBufferIndex].position(0);
                        //log("fhy, position after: " + inputBuffers[inputBufferIndex].position());
                        inputBuffers[inputBufferIndex].put(srcBuffer.array(), 0, srcBuffer.array().length);
                        inputBuffers[inputBufferIndex].position(0);
                        try {
                            codec.queueInputBuffer(inputBufferIndex, 0, srcBuffer.array().length, m_presentationTimeUs, 0);
                            m_presentationTimeUs += 100 * 1000;
                        } catch (MediaCodec.CryptoException e) {
                            e.printStackTrace();
                        }
			   srcBuffer = null ;
                    }
                    MediaCodec.BufferInfo info = new MediaCodec.BufferInfo();
                    try {
                        outputBufferIndex = codec.dequeueOutputBuffer(info, DEQUEQUE_TIMEOUT);
                    }
                    catch (IllegalStateException e) {
                              e.printStackTrace();
                              continue;
                    }
                    vlog("internalStartEncode(), dequeueOutputBuffer, index: " + outputBufferIndex + ", offset: " + info.offset + ", size: " + info.size + ", flag: " + info.flags);
                    if (outputBufferIndex >= 0) {// outputBuffer is ready to be processed or rendered.
                        outputBuffers[outputBufferIndex].position(0);
                        if((DEBUG_ACODEC_WRITE == true )&&(null  != mCodecFilename))
                        {
                             muxer.writeSampleData(0,  outputBuffers[outputBufferIndex],
                             info);
                        }
			else if(mStreamOut!= null)
			{
                            byte[] tempBuffer = new byte[info.size];
                            outputBuffers[outputBufferIndex].get(tempBuffer);
                            outputBuffers[outputBufferIndex].position(0);
                            try 
                            {
                            mStreamOut.write(tempBuffer, 0, tempBuffer.length);
                            mStreamOut.flush();
                            vlog("writeBuffertomodem: " + tempBuffer.length + ", " + Integer.toHexString(tempBuffer[0]&0xff)
                            + " " + Integer.toHexString(tempBuffer[1]&0xff) + " " + Integer.toHexString(tempBuffer[2]&0xff)
                            + " " + Integer.toHexString(tempBuffer[3]&0xff) + " " + Integer.toHexString(tempBuffer[4]&0xff)
                            + " " + Integer.toHexString(tempBuffer[5]&0xff) + " " + Integer.toHexString(tempBuffer[6]&0xff)
                            + " " + Integer.toHexString(tempBuffer[7]&0xff) + " " + Integer.toHexString(tempBuffer[8]&0xff)
                            + " " + Integer.toHexString(tempBuffer[9]&0xff));
                            //outFn.write(tempBuffer, 0, tempBuffer.length);
                            } 
                            catch (IOException e)
                            {
                              // TODO Auto-generated catch block
                              e.printStackTrace();
                            }
    			}
                  
                        vlog("dec compelet");
                        codec.releaseOutputBuffer(outputBufferIndex, false);
                    } else if (outputBufferIndex == MediaCodec.INFO_OUTPUT_BUFFERS_CHANGED) {
                        log("internalStartEncode(), INFO_OUTPUT_BUFFERS_CHANGED");
                        outputBuffers = codec.getOutputBuffers();
                    } else if (outputBufferIndex == MediaCodec.INFO_OUTPUT_FORMAT_CHANGED) {
                        // Subsequent data will conform to new format.
                       if((DEBUG_ACODEC_WRITE == true )&&(null  != mCodecFilename))
                       {
                           format = codec.getOutputFormat();
                           int width = format.getInteger(MediaFormat.KEY_WIDTH);
                           int hight =  format.getInteger(MediaFormat.KEY_HEIGHT);
                           String mine   =  format.getString(MediaFormat.KEY_MIME) ;
                           log("internalStartEncode(), INFO_OUTPUT_FORMAT_CHANGED width " + width +":hight:"+hight +":mine:"+ mine);
                           try {
                           // Throws exception b/c start() is not called.
                                muxer = new MediaMuxer(mCodecFilename, MediaMuxer.OutputFormat.MUXER_OUTPUT_MPEG_4);
                           }catch(java.io.IOException e){
                          }
                          muxer.addTrack(format);
                          muxer.start();
                       }
                    }
		    else  if ((info.flags & MediaCodec.BUFFER_FLAG_CODEC_CONFIG) != 0) {
				
		    }
                }
                log("internalStartEncode() X");

                codec.stop();
                codec.release();
                codec = null;
                synchronized(m_GetBuffer) {
                     m_RingBuffer.clear();
                }
	       synchronized(m_StopLock) {
                     m_StopLock.notify();
                }
	        muxer.stop();
                muxer.release();
            }
        };
        mWorkThread = new Thread(mainRun);
        mWorkThread.start();
    }
    public void onCopyPreviewFrame(byte[] data, Camera camera) {
        vlog("VT_TS Up onCopyPreviewFrame() E m_iframe" + m_iframe );
        if (m_bStarted && (data != null) && (data.length > 0) && (camera != null)) {
            ByteBuffer buffer = ByteBuffer.allocate(BUFFER_SIZE);//data.length);
            buffer.put(data, 0, BUFFER_SIZE);//data.length);
            /*log("fhy onPreviewFrame() m_iframe: " + m_iframe + ", data.length: " + BUFFER_SIZE);//data.length);
            log("fhy onPreviewFrame() , first bytes: " + data[0] + " " + data[1] + " " + data[2] + " " + data[3] + " " + data[4]
            + " " + data[5] + " " + data[6] + " " + data[7] + " " + data[8] + " " + data[9]);
            log("fhy onPreviewFrame(), last bytes: " + data[BUFFER_SIZE - 10] + " " + data[BUFFER_SIZE - 9]
            + " " + data[BUFFER_SIZE - 8] + " " + data[BUFFER_SIZE - 7] + " " + data[BUFFER_SIZE - 6] + " " + data[BUFFER_SIZE - 5]
            + " " + data[BUFFER_SIZE - 4] + " " + data[BUFFER_SIZE - 3] + " " + data[BUFFER_SIZE - 2] + " " + data[BUFFER_SIZE - 1]);*/
            if (DUMP_CAMERA) dump("/data/camera_preview" + m_iframe, data, BUFFER_SIZE);
	    if( true ==m_bStarted)
	    {
	         mCamera.addCallbackBuffer(data);
	    }
            synchronized(m_GetBuffer) {
                m_RingBuffer.add(buffer);
                m_iframe++;
                m_GetBuffer.notify();
            }
        }
    }

@Override
   public void onPreviewFrame(
                final byte[] data, android.hardware.Camera camera) {
                   vlog("onPreviewFrame E");
				   
	       if(!DEBUG_ACODEC_RECORD)
	       {
                   mCamera.addCallbackBuffer(data);
	       }
	      else
        	{
        
                 	mHandler.post(new Runnable() {
                 	@Override
                 	public void run() {
                 	onCopyPreviewFrame(data, mCamera);
                 	}
                 	});
        	}
         }

    private void dump(String fn, byte[] data, int length) {
        OutputStream outFn = null;
        FileOutputStream fo= null;
        try {
            fo  = new FileOutputStream(fn) ;
            if (fo == null)
            {
                return ;
            }
            outFn = new BufferedOutputStream(fo);
            if(outFn == null)
            {
                fo.close() ;
                return ;
            }
            outFn.write(data, 0, length);
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e){
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        try{
            outFn.close();
            fo.close() ;
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
