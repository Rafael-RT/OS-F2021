dir=/lofsdisk
echo 'Toizhanov' > $dir/file1
echo 'Rafael' > $dir/file2
sudo chmod 777 $dir
mkdir -p $dir/{bin,lib64,lib}
mkdir -p $dir/lib/x86_64-linux
cp /bin/{ls,bash,echo,cat} $dir/bin 
libs_ls="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"
for lib in $libs_ls; do
    sudo cp "$i" "${dir}${i}"; 
done
libs_bash="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"
for lib in $libs_bash; do
    sudo cp "$i" "${dir}${i}";
done
libs_echo="$(ldd /bin/echo | egrep -o '/lib.*\.[0-9]')"
for lib in $libs_echo; do
    sudo cp "$i" "${dir}${i}";
done
libs_cat="$(ldd /bin/cat | egrep -o '/lib.*\.[0-9]')"
for lib in $libs_cat; do
    sudo cp "$i" "${dir}${i}";
done
gcc ex2.c -o ex2.out
chmod +x ex2.out
cp ./ex2.out $dir
chmod +x $dir/ex2.out
sudo chroot $dir ./ex2.out > ex2.txt
./ex2.out > ex2.txt
