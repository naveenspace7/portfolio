$ docker run -it <docker-image>
-i interactive map
-t terminal 

$ docker run -p <intended-host-port>:<actual-docker-port> <image-name>

Volume mapping:
$ docker run -v <host-directory>:<docker-directory> mysql
$ docker run -v /opt/datadir:/var/lib/mysql mysql

$ docker inspect <container-name>

$ docker logs <container-name>

$ docker ps
lists all the containers running

$ docker ps -a
lists all the containers which are stopped and running

$ docker run [--name <custom-name>] image
if the name is not chosen, then docker automatically creates a name

$ docker rmi <images..>
Before an image can be deleted, all it's container instances have to be stopped and deleted (even the ones not running).

$ docker rm <container-name>

$ docker run -e ENV_VAR=val <image-name>

These environment variables are displayed under inspect command for a particular image.

$ docker history <image-name>
gives the sizes of each layer in the image specified

___

# Creating custom docker image

Create a file Dockerfile

```
FROM ubuntu # base OS or image, 

RUN apt update
RUN apt install python

RUN pip install flask
RUN pip install flash-mysql

COPY . /opt/source-code

ENTRYPOINT FLASH_APP=/opt/source-code/app.py flask run
```

For building the image, run:
$ docker build Dockerfile -t naveen/my-custom-app

$ docker push naveen/my-custom-app

INSTRUCTION ARGUMENT

RUN terminal command

COPY src dest

