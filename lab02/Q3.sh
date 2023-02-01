touch concat.txt
for i in {1..4}
	do
	dirname="test0$i"
	cd $dirname
	for j in {1..2};
	do
	cd $j
	cat text.txt >> /home/student/Downloads/mehdi/lab02/concat.txt
	cd ..
	done
	cd ..
	done