#!/usr/bin/perl -w

use ExtUtils::MakeMaker;

WriteMakefile(
  NAME => "dbdoc",
	VERSION => "0.03",
	EXE_FILES => [qw(dbdoc)]
);
