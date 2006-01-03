
DATABASE TEST1

MAIN
  DEFINE prSystables RECORD LIKE systables.*

	INITIALIZE prSystables.* LIKE systables.*
	INITIALIZE prSystables.* LIKE "informix".systables.*
END MAIN
