while true;do
./make
./test
./code
if diff code.out test.out;then
echo AC
else
echo WA
read p
fi
done
