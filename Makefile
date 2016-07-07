Q = @

all: doc program

doc: doc/doxygen.config
	@doxygen -s doc/doxygen.config >/dev/null
	@echo Documentation created

program:
	$(Q)$(MAKE) -C src

clean:
	$(Q)$(MAKE) -C src clean
	$(Q)rm doc/html doc/latex -rf

.PHONY: doc clean
