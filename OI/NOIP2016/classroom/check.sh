while true;do
./make
./brute
./classroom
if diff classroom.out brute.out;then
echo AC
else 
echo WA
read p
fi
done
