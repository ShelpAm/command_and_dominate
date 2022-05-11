submodule_list=(glfw small_utility)

cd thirdparty/
for i in ${submodule_list[@]}
do
	 cd $i
	git pull > /dev/null
	cd ..
	echo $i updated.
done

echo Updating done.
