#!/usr/bin/perl -w

#
# Generate a single test suite based on all test files that founds in
# tools/test/buil_tests of aubit 4gl
# Copy all of those files found to this directory.
#
# The test suite uses cppunit to test it.
#

use strict;
use POSIX;

my @fileList;

# Generate the 
# @param The Directory where the file names should be finded.
# Warning - This does not work when there are a 4gl in the current dir
sub getFglModules
{
  my $dir = shift;
  my $files = `find $dir -name \*.4gl`;
  @fileList = split(/\n/,$files);
  my $file;
}

# Generate the 4gl test suite C++ source file
sub genFglTestCpp
{
  open(FGLTESTCPP, "> GenFglTest.cpp") || 
    die "Cant open GenFglTest.cpp : $!";
  printf FGLTESTCPP qq|
/**
 * \@file
 * This test suite was generated by genTestSuite.pl based on the 4gl files
 * that found in a directory
 */

#include <stdio.h>
#include "GenFglTest.h"

// \@todo : Declare this in a .h
int parse_4gl(const char *fileName);

#define PARSE_OK 0

// Registers the fixture into the 'registry'
//CPPUNIT_TEST_SUITE_REGISTRATION( GenFglTest );


void 
GenFglTest::setUp()
{
}


void 
GenFglTest::tearDown()
{
}
  |;
  my $file;
  foreach $file ( @fileList )
  {
     my $functionName = filterFile($file);
     printf FGLTESTCPP qq|
void GenFglTest::$functionName()
{
  FglParse *fglParse = new FglParse("$file");
  CPPUNIT_ASSERT_EQUAL(
    PARSE_OK,fglParse->getParsingResult()
  );
	delete fglParse;
}
|;
  }
  close (FGLTESTCPP);
}

# Generate the .h file that contains the declaration of the tests
sub genFglTestH
{
  open(FGLTESTH, "> GenFglTest.h") || 
    die "Cant open GenFglTest.h : $!";
  printf FGLTESTH qq|
#ifndef GENFGLTEST_H
#define GENFGLTEST_H

//#include <cppunit/extensions/HelperMacros.h>

#include <cppunit/extensions/HelperMacros.h>
#include "FglParse.h"

class GenFglTest : public CppUnit::TestFixture
{
public:
  static CppUnit::Test *suite()
  {
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite(
      "GenFglTest" 
    );
|;
  my $file;
  foreach $file ( @fileList )
  {
    my $functionName = filterFile($file);
    printf FGLTESTH qq|
    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "$functionName",
      &GenFglTest::$functionName ) 
		);|;
  }
  printf FGLTESTH qq|
    return suiteOfTests;
	}
|;
  foreach $file ( @fileList )
  {
    my $functionName = filterFile($file);
    printf FGLTESTH qq|
  void $functionName ();
|;
  }
  printf FGLTESTH qq|
  void setUp();
  void tearDown();
};

#endif
|;
  close (FGLTESTH);
}

sub genMain
{
  open(MAINTESTCPP, "> MainGenFglTest.cpp") || 
    die "Cant open MainGenFgltest.cpp : $!";
  printf MAINTESTCPP qq|
/**
 * \@file
 * The main test file for the new 4gl parser of fgldocumenter.
 * This file was generated by genTestSuite.pl
 */

//#include <cppunit/CompilerOutputter.h>
//#include <cppunit/extensions/TestFactoryRegistry.h>
//#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/ui/text/TestRunner.h>
#include "GenFglTest.h"


int main( int argc, char **argv)
{
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( GenFglTest::suite() );
  runner.run();
  return 0;
}

|;
  close(MAINTESTCPP);
}

# Take of the file extension of 4gl to generate the name of the testing 
# function
sub filterFile() {
  my $file = shift;

	my $retFile = $file;
	$retFile =~ s/\//_/g;
	$retFile =~ s/\.4gl//;
  return $retFile;
}

getFglModules("fgl");
genMain();
genFglTestCpp();
genFglTestH();

