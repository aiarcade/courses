for c in `cat input.txt`; do
	echo $c > in.txt;
	echo "Running GPU code"
	/usr/bin/time  -a -o outgpu.txt  --format "%E" ./vector-add-gpu/Debug/vector-add-gpu < in.txt ;
	echo "Running CPU code"
	/usr/bin/time  -a -o outplain.txt  --format "%E" ./vector-add-plain/Debug/vector-add-plain < in.txt ;
	echo "Running SHM code"
	/usr/bin/time  -a -o outshm.txt  --format "%E" ./vector-add-shm/Debug/vector-add-shm < in.txt ;
done
