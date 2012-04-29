" An example for a vimrc file.
"
" Maintainer:	Bram Moolenaar <Bram@vim.org>
" Last change:	2008 Jul 02
"
" To use it, copy it to
"     for Unix and OS/2:  ~/.vimrc
"	      for Amiga:  s:.vimrc
"  for MS-DOS and Win32:  $VIM\_vimrc
"	    for OpenVMS:  sys$login:.vimrc

" When started as "evim", evim.vim will already have done these settings.
if v:progname =~? "evim"
  finish
endif

" Use Vim settings, rather then Vi settings (much better!).
" This must be first, because it changes other options as a side effect.
set nocompatible

" allow backspacing over everything in insert mode
set backspace=indent,eol,start

if has("vms")
  set nobackup		" do not keep a backup file, use versions instead
else
  set backup		" keep a backup file
endif
set history=50		" keep 50 lines of command line history
set ruler		" show the cursor position all the time
set showcmd		" display incomplete commands
set incsearch		" do incremental searching

" For Win32 GUI: remove 't' flag from 'guioptions': no tearoff menu entries
" let &guioptions = substitute(&guioptions, "t", "", "g")

" Don't use Ex mode, use Q for formatting
map Q gq

" CTRL-U in insert mode deletes a lot.  Use CTRL-G u to first break undo,
" so that you can undo CTRL-U after inserting a line break.
inoremap <C-U> <C-G>u<C-U>

" In many terminal emulators the mouse works just fine, thus enable it.
if has('mouse')
  set mouse=a
endif

" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
  syntax on
  set hlsearch
endif

" Only do this part when compiled with support for autocommands.
if has("autocmd")

  " Enable file type detection.
  " Use the default filetype settings, so that mail gets 'tw' set to 72,
  " 'cindent' is on in C files, etc.
  " Also load indent files, to automatically do language-dependent indenting.
  filetype plugin indent on

  " Put these in an autocmd group, so that we can delete them easily.
  augroup vimrcEx
  au!

  " For all text files set 'textwidth' to 78 characters.
  autocmd FileType text setlocal textwidth=78

  " When editing a file, always jump to the last known cursor position.
  " Don't do it when the position is invalid or when inside an event handler
  " (happens when dropping a file on gvim).
  " Also don't do it when the mark is in the first line, that is the default
  " position when opening a file.
  autocmd BufReadPost *
    \ if line("'\"") > 1 && line("'\"") <= line("$") |
    \   exe "normal! g`\"" |
    \ endif

  augroup END

else

  set autoindent		" always set autoindenting on

endif " has("autocmd")

" Convenient command to see the difference between the current buffer and the
" file it was loaded from, thus the changes you made.
" Only define it when not defined already.
if !exists(":DiffOrig")
  command DiffOrig vert new | set bt=nofile | r # | 0d_ | diffthis
		  \ | wincmd p | diffthis
endif

" Begin --------------My config --------------
" set mapleader
let mapleader = ","
" when .vimrc is edited, reload it
autocmd! bufwritepost .vimrc source ~/.vimrc

" colortheme
colorscheme darkblue

" Not need toolbar
set guioptions-=T
set guioptions-=m


" zh_CN Vim DOC
if version > 603
	set helplang=cn
endif

" tabstop
set tabstop=4
set sts=4
set	shiftwidth=4
set expandtab
set autoindent
set textwidth=80

" line number 
set nu

" //////////////Some Plugins/////////////////////
" outliner plugins


" Tlist setting
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
let Tlist_Ctags_Cmd='/usr/bin/ctags'

" winManager setting
let g:winManagerWindowLayout='FileExplorer|TagList'
nmap <leader>wm :WMToggle<cr>

" for cscope
" 加载当前目录的cscope.out
if has("cscope")
    set csprg=/usr/bin/cscope
    set csto=1
    set cst
    set nocsverb
    " add any database in current directory
    if filereadable("cscope.out")
        cs add cscope.out
    endif
    set csverb
endif

"set cscopequickfix=s-,c-,d-,i-,t-,e-

" 查找C语言符号，查找函数名，宏出现的地方
nmap <leader>cs :cs find s <C-R>=expand("<cword>")<CR><CR>
nmap <F7> :cs find s 
" 查找函数定义的地方
nmap <leader>cg :cs find g <C-R>=expand("<cword>")<CR><CR>
" 查找调用本函数函数
nmap <leader>cc :cs find c <C-R>=expand("<cword>")<CR><CR>
" 查找指定的字符串
nmap <leader>ct :cs find t <C-R>=expand("<cword>")<CR><CR>
" 查找egrep
nmap <leader>ce :cs find e <C-R>=expand("<cword>")<CR><CR>
" 查找并打开文件，类似vim的find
nmap <leader>cf :cs find f <C-R>=expand("<cword>")<CR><CR>
" 查找包含文本
nmap <leader>ci :cs find i <C-R>=expand("<cword>")<CR><CR>
" 查找本函数调用的函数
nmap <leader>cd :cs find d <C-R>=expand("<cword>")<CR><CR>

" miniBufExplorer
let g:miniBufExplMapCTabSwitchBufs=1
let g:miniBufExplMapWindowNavVim=1
let g:miniBufExplMapWindowNavArrows=1

" for Grep
nnoremap <slient> <F3> :Grep<CR>

" for complete
set completeopt=longest,menu,preview
"  python commplete
autocmd FileType python set omnifunc=pythoncomplete#Complete
" cpp complete 
" ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .

" supertab setting
"let g:SuperTabRetainCompletionType=2
"let g:SupetTabDefaultCompletionType="<C-X><C-O>"

" fold method
set foldmethod=syntax
set foldlevel=100

" fonts
set guifont=Bitstream\ Vera\ Sans\ Mono\ 11

" for doxygen
"let g:DoxygenToolkit_briefTag_pre="@soul"
let g:DoxygenToolkit_paramTag_pre="@Param"
let g:DoxygenToolkit_returnTag="@Returns"
let g:DoxygenToolkit_blockHeader="----------------------------------"
let g:DoxygenToolkit_blockFooter="----------------------------------"
let g:DoxygenToolkit_authorName="soullight"
"let g:DoxygenToolkit_licenseTag="gnu"
let g:DoxygenToolkit_briefTag_funcName="yes"

" tags
set tags+=~/.vim/tags/tags

" current tags
map <C-F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .

" wiki
let g:vimwiki_use_mouse=1
let g:vimwiki_list=[{'path':'~/wiki'}]
let g:vimwiki_table_auto_fmt = 0

" vim gtd
let g:wikigtd_index='task/task'

" task paper
function! s:taskpaper_setup()
    nnoremap <buffer> <silent> <Leader>tn 
        \ :<C-u>call taskpaper#toggle_tag('next', '')<CR>
endfunction

augroup vimrc-taskpaper
    autocmd!
    autocmd FileType taskpaper call s:taskpaper_setup()
augroup END


" End   ----My config --------------
