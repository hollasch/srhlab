setlocal enabledelayedexpansion

set x=x
for %%f in (a b c d e) do set x=!x!-%%f
@echo x = %x%
