database test1
main
define a integer
let a=1
	unload to "./p1.unl" select * from systables where tabid=a
end main
