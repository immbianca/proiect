FROM gcc:latest
WORKDIR /usr/src/program
COPY program.cpp .
RUN gcc -o program program.cpp -lstdc++
CMD ["./program"]