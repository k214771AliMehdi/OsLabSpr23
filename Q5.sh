#! /bin/bash
touch FileNames.txt
for i in {1..5}
	do
	dirname="test$i"
	rm -rf $dirname
	done
