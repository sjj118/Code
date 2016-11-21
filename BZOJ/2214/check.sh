while true;do
echo making..
./make
echo shift
./code
echo std
./std
echo checking..
./check
if [ $? -eq 1 ];then
echo WA
read p
else
echo AC
fi
done
