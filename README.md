# System-Application-Monitor

COMP3000 - Final Project

## BUILDING REQUIREMENTS
#### libprocps
> sudo apt install libprocps4 libprocps4-dev

##### cpupower
> sudo apt install cpupower <br>
<p>
Please note, cpupower requires kernal specific packages.
The following installations were used for kernel 4.13.0-38: </p>
> sudo apt install linux-tools-4.13.0-38-generic
> sudo apt install linux-cloud-tools-4.13.0-38-generic


## Background

Using the Linux operating system, this utility offers a simple to use system monitor, that provides system information for temperatures and frequencies of the cpu and its components. 
In addition, the software also the ability to detect memory leaks from running processes.


## Motivation

The built in software does not have this capability and requires more work that necessary.

## Goals

Our goal is provide the user with a friendly graphical interface that allows the user to view their system's information without doing a ton of work. We also aim to provide the user with useful tools that detect potential problems, such as a memory leak.

## Authors

* **Mohamad Yassine** [Github Page](https://github.com/moyass)
* **Tamara Alhajj** [Github Page](https://github.com/TamaraAlhajj)
