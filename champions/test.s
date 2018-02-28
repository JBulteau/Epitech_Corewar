.name "aze"
.comment "testing fncs"
l2:
sti r1,%:live,%1
and r1,%0,r1
live: live %1
zjmp %:live
	zjmp %:l2
	zjmp %:l2






	
aff r3
