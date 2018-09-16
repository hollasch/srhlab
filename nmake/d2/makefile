
walk:
	@echo.
        @echo d2 -------------------------------------------------------------------------
	@echo.
	@echo MAKEDIR = $(MAKEDIR)
	@echo x_DIR = $(x_DIR)
	@echo derived root = $(MAKEDIR:\d2=)
        @echo TOPVAR = $(TOPVAR)
	@echo 1 env_foo=%%env_foo%%
	@set env_foo=$(MAKEDIR) : d2
	@echo 2 env_foo=%%env_foo%%
