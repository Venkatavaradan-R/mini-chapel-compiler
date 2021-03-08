cd ..
make
while true
do
printf "\n----------------------------\n"
printf "\n Select test file \n1)test1.go\n2)test2.go\n3)test3_for.go\n4)test3_wrong.go\n5)test4_fun.go\n\nEnter option:"
read option
case $option in 
    1) ./gocompiler test/test.chpl ;;

esac
done;
make clean;