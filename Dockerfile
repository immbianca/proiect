FROM gcc:latest
WORKDIR /usr/src/main
COPY main.cpp .
RUN gcc -o main main.cpp -lstdc++
CMD ["./main"]