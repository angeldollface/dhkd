build: ; gcc main.c -lX11 -o dhkd
clean: ; rm -rf dhkd
perm: ; chmod a+x dhkd
