#-------------------------------------------------------------------------
#
# Makefile for the bootstrap module
#
# $PostgreSQL: pgsql/src/backend/bootstrap/Makefile,v 1.34 2006/03/07 01:03:12 tgl Exp $
#
#-------------------------------------------------------------------------

subdir = src/backend/bootstrap
top_builddir = ../../..
include $(top_builddir)/src/Makefile.global

override CPPFLAGS := -I$(srcdir) $(CPPFLAGS)

OBJS= bootparse.o bootstrap.o 

all: SUBSYS.o

SUBSYS.o: $(OBJS)
	$(LD) $(LDREL) $(LDOUT) $@ $^


# bootscanner is compiled as part of bootparse
bootparse.o: $(srcdir)/bootscanner.c

# See notes in src/backend/parser/Makefile about the following two rules

$(srcdir)/bootparse.c: $(srcdir)/bootstrap_tokens.h ;

$(srcdir)/bootstrap_tokens.h: bootparse.y
ifdef YACC
	$(YACC) -d $(YFLAGS) $<
	mv -f y.tab.c $(srcdir)/bootparse.c
	mv -f y.tab.h $(srcdir)/bootstrap_tokens.h
else
	@$(missing) bison $< $@
endif

$(srcdir)/bootscanner.c: bootscanner.l
ifdef FLEX
	$(FLEX) $(FLEXFLAGS) -o'$@' $<
else
	@$(missing) flex $< $@
endif

# Force these dependencies to be known even without dependency info built:
bootstrap.o bootparse.o: $(srcdir)/bootstrap_tokens.h


# bootparse.c, bootstrap_tokens.h, and bootscanner.c are in the distribution
# tarball, so they are not cleaned here.
clean:
	rm -f SUBSYS.o $(OBJS)
# And the garbage that might have been left behind by partial build:
	@rm -f y.tab.h y.tab.c y.output lex.yy.c


# This is unusual:  We actually have to build some of the parts before
# we know what the header file dependencies are.  
dep depend: bootparse.c bootscanner.c bootstrap_tokens.h
	$(CC) -MM $(CFLAGS) *.c >depend

ifeq (depend,$(wildcard depend))
include depend
endif
