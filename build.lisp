(compile-file "add.lisp" :system-p t)

(c:build-static-library "add" 
			:lisp-files '("add.o")
			:init-name "init_add")
(quit)
