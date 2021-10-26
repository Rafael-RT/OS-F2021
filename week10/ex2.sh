mkdir week01
cd week01
echo asfas > file.txt
cd ..
link week01/file.txt _ex2.txt
ls -i _ex2.txt
find . -inum 1450606
find . -inum 1450606 > ex2.txt
find . -inum 1450606 -exec rm {} \; >> ex2.txt

