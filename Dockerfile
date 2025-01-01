FROM gcc:latest
RUN apt-get update && apt-get install -y libgraph-dev
WORKDIR /usr/src/program
COPY program.cpp .
RUN gcc -o program program.cpp -lstdc++
CMD ["./program"]