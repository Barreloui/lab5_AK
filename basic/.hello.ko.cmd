cmd_/home/maksim/AK2/lab5/basic/hello.ko := ccache arm-eabi-ld -r  -EL -T ./scripts/module-common.lds -T ./arch/arm/kernel/module.lds  --build-id  -o /home/maksim/AK2/lab5/basic/hello.ko /home/maksim/AK2/lab5/basic/hello.o /home/maksim/AK2/lab5/basic/hello.mod.o ;  true
