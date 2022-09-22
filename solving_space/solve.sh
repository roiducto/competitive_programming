if [ $# -eq 0 ]
  then
    read -p "filename: " var
else
	var="$1"
fi

read -n 1 -p "test case? [y/(n)/q] " var
case $var in
[Yy] ) cp ../template/base_testcase.cpp $1.cpp;;
[Nn] | $enter ) cp ../template/base.cpp $1.cpp;;
[Qq] ) exit;;
* ) echo "Please answer yes or no. ";;
esac
vim +13 $1.cpp
