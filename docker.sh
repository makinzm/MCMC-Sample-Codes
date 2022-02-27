cd vm_env
docker build . -t mcmc -f Dockerfile_cpp
docker run -it -v ~/development/MCMC-Sample-Codes:/root/files mcmc