;;;;;;一般性设置;;;;;;;
;; 关闭开机画面
(setq inhibit-startup-message t)
;; 关掉出错的提示声音
(setq visible-bell t)
;; 显示列号
(setq column-number-mode t)
;; 设置kill ring
(setq kill-ring-max 200)
;; 列最长80
(setq default-fill-column 80)
;; 不用TAB字符来indent
(setq-default indent-tabs-mode nil)
(setq default-tab-width 8)
(setq tab-stop-list ())
;(loop for x downfrom 40 to 1 do
;      (setq tab-stop-list (cons (* x 4) tab-stop-list)))
;; sentence-end 识别中文标点
(setq sentence-end "\\([。！？]\\|……\\|[.?!][]\"')}]*\\($\\|[ \t]\\)\\)[ \t\n]*")
(setq sentence-end-double-space nil)
;; major mode 设置为 text-mod1e
(setq default-major-mode 'text-mode)
;;括号匹配时显示另外一边的括号，而不是烦人的跳到另一个括号
(show-paren-mode t)
(setq show-paren-style 'parentheses)
;; 在标题栏中显示buffer的名字
(setq frame-title-format "emacs@%b")
;; 直接显示图片
(auto-image-file-mode)
;; 语法加亮
(global-font-lock-mode t)
;; 备份版本控制
(setq version-control t)
(setq kept-new-versions 3)
(setq delete-old-versions t)
(setq kept-old-versions 2)
(setq dired-kept-versions 1)
;; 让 dired 可以递归的拷贝和删除目录
(setq dired-recursive-copies 'top)
(setq dired-recursive-deletes 'top)
;; 一个简单的办法设置 auto-mode-alist, 免得写很多 add-to-list.
(mapcar
 (function (lambda (setting)
	     (setq auto-mode-alist
		   (cons setting auto-mode-alist))))
 '(("\\.xml$".  sgml-mode)
   ("\\\.bash" . sh-mode)
   ("\\.rdf$".  sgml-mode)
   ("\\.session" . emacs-lisp-mode)
   ("\\.l$" . c-mode)
   ("\\.css$" . css-mode)
   ("\\.cfm$" . html-mode)
   ("gnus" . emacs-lisp-mode)
   ("\\.idl$" . idl-mode)))

;; 个人信息
(setq user-full-name "Wang Yaofeng")
(setq user-mail-address "imousewyfzml@gmail.com")
;; 防止页面滚动时跳动
(setq scroll-margin 3
      scroll-conservatively 10000)