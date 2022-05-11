submodule_list=(glfw small_utility)

cd thirdparty/
for i in ${submodule_list[@]}
do
	 cd $i
	git pull > /dev/null
	cd ..
	echo $i updated.
done

cd ..
git submodule update > /dev/null
echo Updating done.
