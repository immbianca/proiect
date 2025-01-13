FROM gcc:latest
WORKDIR /usr/src/app
COPY main.cpp .
RUN gcc -o turnurile_hanoi main.cpp -lstdc++
CMD ["./turnurile_hanoi"]