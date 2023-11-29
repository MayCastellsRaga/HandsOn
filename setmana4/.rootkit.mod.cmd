cmd_/home/may/HandsOn/setmana4/rootkit.mod := printf '%s\n'   rootkit.o | awk '!x[$$0]++ { print("/home/may/HandsOn/setmana4/"$$0) }' > /home/may/HandsOn/setmana4/rootkit.mod
