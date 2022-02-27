###
# https://atmarkit.itmedia.co.jp/ait/articles/1806/14/news018.html
###

for dir in "cpp_file" "py_file" "c_file"
do

if [ -e $dir ]
then 
    echo $dir" is already created"
else
    mkdir $dir
fi

EXT=(${dir//_/ })

echo ${EXT[0]}

for f in *.${EXT[0]}
do 
mv $f $dir
done

done
