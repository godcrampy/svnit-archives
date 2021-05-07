sudo docker rm $(sudo docker stop $(sudo docker ps -a -q --filter ancestor=graphics --format="{{.ID}}"))

sudo docker rmi graphics

sudo docker build -t graphics . 

sudo docker run --name graphics -it --net=host -e DISPLAY -v /tmp/.X11-unix graphics bash
