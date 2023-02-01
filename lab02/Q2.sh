for i in {1..4}
	do
	dirname="test0$i"
	mkdir $dirname
	cd $dirname
	for j in {1..2};
	do
	mkdir $j
	cd $j
	date > text.txt
	cd ..
	done
	cd ..
	done