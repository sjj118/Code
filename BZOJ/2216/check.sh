while true;do
echo making..
./make
echo std
./std
echo code
./code
echo comparing..
if diff code.out std.out;then
echo AC
else
echo WA
read p
fi
done
