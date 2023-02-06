#! /bin/bash
touch FileNames.txt
for i in {1..4}
	do
	dirname="test$i"
	cd $dirname
	for j in {1..2}
	do
	cd 0$j
	ls >> /home/kali/oslab/FileNames.txt
	cd ..
	done
	cd ..
	done
