#!/usr/bin/perl -w

# ==============================================================================
# This new version use ExtUtils::Installed to see where the things are installed
# ==============================================================================

package FglDocumenter::FglDocLocation;

use strict;
use ExtUtils::Installed;

# ===========================================================
# Returns the location where the fgldoc is instaled
# ===========================================================
sub getLocation
{
  my ($inst) = ExtUtils::Installed->new();
  my (@directories) = $inst->directories("FglDocumenter");
	my $locationDir;
	foreach my $directory (@directories)
	{
		if ( $directory =~ /.*FglDocumenter$/ )
		{
			$locationDir = $directory;
		}
	}
  return $locationDir;
}
return 1;

