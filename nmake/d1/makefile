
walk: d1a d1b
	@echo.
        @echo d1 -------------------------------------------------------------------------
	@echo.
	@echo MAKEDIR = $(MAKEDIR)
	@echo x_DIR = $(x_DIR)
	@echo derived root = $(MAKEDIR:\d1=)
        @echo TOPVAR = $(TOPVAR)
	@setlocal
	@echo 1 env_foo=%%env_foo%%
	@set env_foo=$(MAKEDIR) : d1
	@echo 2 env_foo=%%env_foo%%
	! cd $** && \
          $(MAKE)/$(MAKEFLAGS) walk x_DIR=$(MAKEDIR)\$** && \
          cd $(MAKEDIR)
        @endlocal
