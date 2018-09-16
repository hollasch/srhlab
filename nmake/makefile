# ----------------------------------------------------------------------------
#
# Demonstration Makefile
#
#     This makefile contains a variety of small examples illustrating nmake
#     rules and quirks.  Run 'nmake' to see a list of available examples.
#
#
# NOTES:
#
#     (1)  A space before the rule colon is necessary for single-letter
#          targets so they aren't confused with drive letters.
#
#     (2)  You can use wildcards (* and ?) in dependency lines.
#
# ----------------------------------------------------------------------------
# Filename Macros
#
#     $@   Current target's full name (path, base name, extension), as
#          currently specified.
#
#     $$@  Current target's full name (path, base name, extension), as
#          currently specified.  Valid only as a dependent in a dependency.
#
#     $*   Current target's path and base name minus file extension.
#
#     $**  All dependents of the current target.
#
#     $?   All dependents with a later timestamp than the current target.
#
#     $<   Dependent file with a later timestamp than the current target.
#          Valid only in commands in inference rules.
#
# Modifiers
#
#     To specify part of a predefined filename macro, append a macro modifier
#     and enclose the modified macro in parentheses.  For example, $(@F).
#
#     D    Drive plus directory
#     B    Base name
#     F    Base name plus extension
#     R    Drive plus directory plus base name
#
# ----------------------------------------------------------------------------
# Filename-Parts Syntax
#
#     Filename-parts syntax in commands represents components of the first
#     dependent filename (which may be an implied dependent). Filename
#     components are the file's drive, path, base name, and extension as
#     specified, not as it exists on disk. Use %s to represent the complete
#     filename. Use %|[parts]F (a vertical bar character follows the percent
#     symbol) to represent parts of the filename, where parts can be zero or
#     more of the following letters, in any order.
#
#     No Letter    Complete name (same as %s)
#             d    Drive
#             p    Path
#             f    File base name
#             e    File extension
#
#     For example, if the filename is c:\prog.exe: 
#
#         %s   will be c:\prog.exe 
#         %|F  will be c:\prog.exe 
#         %|dF will be c 
#         %|pF will be c:\ 
#         %|fF will be prog 
#         %|eF will be exe 
#
# ----------------------------------------------------------------------------


.SUFFIXES : .x1 .x2 .y1 .y2

# Single colon executes command one file at a time, double colon causes
# command to operate on all out-of-date files at once.

.x1.x2:
    @echo .x1.x2 inference rule:
    @echo $$^@ = $@ ...... Current targ full name
    @echo $$^* = $* ......... Current targ path + base name
    @echo $$^** = $** ..... All dependents
    @echo $$^? = $? ...... All later dependents
    @echo $$^< = $< ...... Dependent file with later timestamp
    @echo.

.y1.y2::
    @echo .y1.y2 batch-mode inference rule:
    @echo $$^< = $<
    @echo.


# ----------------------------------------------------------------------------

all:
    @echo.
    @echo Targets:
    @echo.
    @echo batch ------- Batch mode inference rules
    @echo cdtest ------ CD Test
    @echo defcmd ------ Creating files via default command
    @echo error ------- Error exit test
    @echo emptyaction - Invoke empty action
    @echo envtest ----- Test environment variable contexts
    @echo for --------- For loop command
    @echo inline ------ Inline files
    @echo loop -------- Loop a command through dependents
    @echo macros ------ Print special macro values
    @echo multidep ---- Demonstrates that a common dependency is done once
    @echo multirule --- Execute same rule block multiple times (w/diff names)
    @echo noop -------- Do-nothing target
    @echo recurse ----- Recursive invocation
    @echo semicolon --- Demonstrates semi-colon on target line
    @echo walk -------- Recursive descent



# ----------------------------------------------------------------------------

foo.x2: foo.x1

batch: foo.x2

# ----------------------------------------------------------------------------

defcmd = @echo $? to $@

defcmd-a defcmd-b defcmd-c:
    @copy >nul nul $@

defcmd: defcmd-out-a defcmd-out-b defcmd-out-c

defcmd-out-a : defcmd-a   ; $(defcmd)
defcmd-out-b : defcmd-b   ; $(defcmd)
defcmd-out-c : defcmd-c   ; $(defcmd)

clean::
    del 2>nul def-a def-b def-c



# ----------------------------------------------------------------------------

a.x1 b.x1 c.x1 a.y1 b.y1 c.y1:
    copy >nul nul $@

batch1: a.x2 b.x2 c.x2

batch2: a.y2 b.y2 c.y2

clean::
    del 2>nul *.x1 *.x2 *.y1 *.y2



# ----------------------------------------------------------------------------

cdtest:
    cd
    cd /d C:\\ & cd
    cd

# ----------------------------------------------------------------------------

zzz:: aa
zzz:: bb
zzz:: cc

aa:
    @echo aa

bb:
    @echo bb

cc:
    @echo cc

zzz::
    @echo -- zzz

# ----------------------------------------------------------------------------

loop_list=loop-a loop-b loop-c loop-d loop-e loop-f

loop: loop-x loop-target

loop-target: $(loop_list)
    @!echo Looping on all listed dependents:  $$** = $**
    @!echo Looping on all out-of-date dependents:  $$? = $?

loop-x:
    @echo Building loop test files.
    @copy >nul nul loop-a
    @copy >nul nul loop-b
    @copy >nul nul loop-c
    @sleep 1
    @copy >nul nul loop-target
    @sleep 1
    @copy >nul nul loop-d
    @copy >nul nul loop-e
    @copy >nul nul loop-f
    @copy >nul nul loop-x

clean::
    del 2>nul $(loop_list) loop-x loop-target


# ----------------------------------------------------------------------------

noop:

# ----------------------------------------------------------------------------

envtest:
    @echo x=%%x%%
    set x=Howdy howdy howdy
    @echo x=%%x%%
    envtest
    @echo x=%%x%%
    call envtest
    @echo x=%%x%%
    @echo.
    @echo Observation:
    @echo Setting environment variables in makefile commands modifies the
    @echo environment.  Setting environment variables inside called batch files
    @echo does NOT affect the environment.



# ----------------------------------------------------------------------------
# You can create files on the file (called "inline files" in make parlance.)
# You can either leave the file around after make is done, or you can elect
# to have it cleaned up (removed) before nmake exits.
# ----------------------------------------------------------------------------

inline:
    @echo Kept file:
    type <<inline.txt
This
is
a
test
<<KEEP
    @echo Unkept file:
    type <<
Howdy
Howdy
Howdy
<<NOKEEP
    @echo Repeating kept file:
    type inline.txt

clean::
    del 2>nul inline.txt



# ----------------------------------------------------------------------------
# This rule demonstrates nmake macros.
# ----------------------------------------------------------------------------

macro1=Hello
macro2 = Hello

macros: foo1 foo2
    @echo %^s = %s
    @echo ^%^|F = %|F
    @echo ^%^|dF = %|dF
    @echo ^%^|pF = %|pF
    @echo ^%^|fF = %|fF
    @echo ^%^|eF = %|eF
    @echo.
    @echo ^$@ = $@  // Current target's full name.
    @echo ^$* = $*  // Current target's path and name (less extension).
    @echo ^$** = $** // All dependents of the current target
    @echo ^$? = $?   // All dependents with later timestamp than current target
    @echo $$$$^@ is current target's full name (valid only as dependent in dependency)
    @echo.
    @echo ^$(MAKE) = $(MAKE)
    @echo ^$(MAKEDIR) = $(MAKEDIR)
    @echo ^$(MAKEFLAGS) = $(MAKEFLAGS)
    @echo ^$_NMAKE_VER = $(_NMAKE_VER)
    @echo ^$(macro1) = "$(macro1)"
    @echo ^$(macro2) = "$(macro2)"
    @echo.
    @echo env CMDCMDLINE = %%CMDCMDLINE%%
    @echo ^$(USERNAME) = $(USERNAME)
    @echo ^%%USERNAME^%% = %%USERNAME%%
    @echo ^$(RANDOM) = $(RANDOM)
    @echo ^%%RANDOM^%% = %%RANDOM%%
    @echo chars 6-8 of USERNAME = %%USERNAME:~5,3%%

foo1 foo2:



# ----------------------------------------------------------------------------
# This demonstrates how you can recursively walk a tree with a particular
# target.
# ----------------------------------------------------------------------------

walk: d1 d2
    @echo.
    @echo top ------------------------------------------------------------------------
    @echo.
    @echo MAKEDIR = $(MAKEDIR)
    @echo x_DIR = $(x_DIR)
    @echo derived root = $(MAKEDIR)
    @echo TOPVAR = $(TOPVAR)
    @setlocal
    @echo 1 env_foo=%%env_foo%%
    @set env_foo=$(MAKEDIR) : 1
    @echo 2 env_foo=%%env_foo%%
    ! cd $** && \
      $(MAKE) /$(MAKEFLAGS) walk x_DIR=$(MAKEDIR)\$** && \
      cd $(MAKEDIR)
    @endlocal



# ----------------------------------------------------------------------------
# Here's how you do a loop containing multiple commands in a makefile.
# ----------------------------------------------------------------------------

for:
    for /L %%i in (1,1,5) do \
           echo one %%i \
        && echo two %%i



# ----------------------------------------------------------------------------

multidep: desc thing1 thing2
    @echo Doing xxx block.

desc:
    @echo multdep depends on both thing1 and thing2, and those each depend
    @echo on bigthing.  Note that bigthing is done first and once.
    @echo.

thing1: bigthing
    @echo Doing thing1.

thing2: bigthing
    @echo Doing thing2.

bigthing:
    @echo Doing bigthing.



# ----------------------------------------------------------------------------
# This rule demonstrates that you can work around make's usual behavior of
# "building" a target only once.  If you give the target multiple names, then
# it will build once for each name.
# ----------------------------------------------------------------------------

multirule: mrtarg1 mrtarg2 mrtarg3

mrtarg1 mrtarg2 mrtarg3:
    @echo executing multi-rule block.



# ----------------------------------------------------------------------------
# This rule demonstrates a way to error out of a makefile.
# ----------------------------------------------------------------------------

error:
    @echo Error exit test.
    @exit 10
    @echo Shouldn't get here.


# ----------------------------------------------------------------------------

emptyaction:
    @echo Before empty action.
    $(UNDEFINED_ACTION)
    @echo After empty action.


# ----------------------------------------------------------------------------

semicolon: ; @echo Commands can follow semi-colon on target line.


# ----------------------------------------------------------------------------
# This rule demonstrates recursive invocation.
# ----------------------------------------------------------------------------

recurse :
    $(MAKE)/$(MAKEFLAGS) recurse2

recurse2 :
    $(MAKE)/$(MAKEFLAGS) recurse3

recurse3 :
    @echo Howdy!



# ----------------------------------------------------------------------------

!if ![touch touch-test]
!   message (touch test succeeded)
!   message
!else
!   message (touch test failed)
!   message
!endif

clean::
    del 2>nul touch-test


# ----------------------------------------------------------------------------

!if defined(debug) && ("$(debug)" != "0") && ("$(debug)" != "false")
!    message debug is true.
!else
!    message debug is false.
!endif
