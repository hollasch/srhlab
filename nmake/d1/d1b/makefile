
walk:
	@echo.
        @echo d1b ------------------------------------------------------------------------
	@echo.
	@echo MAKEDIR = $(MAKEDIR)
	@echo x_DIR = $(x_DIR)
        @echo TOPVAR = $(TOPVAR)
	@echo 1 env_foo=%%env_foo%%
	@set env_foo=$(MAKEDIR) : d1b
	@echo 2 env_foo=%%env_foo%%
	@echo derived root = $(MAKEDIR:\d1\d1b=)

