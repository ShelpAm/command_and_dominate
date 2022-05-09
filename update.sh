update_list=(glfw small_utility)

cd thirdparty
for i in ${update_list[@]}
do
	cd $i
	git pull > /dev/null
	echo $i already up to date.
	cd ..
done
echo update finished.
