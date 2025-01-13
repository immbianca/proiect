FROM gcc:latest
WORKDIR /usr/src/app
COPY main.cpp .
RUN gcc -o turnuri_hanoi main.cpp -lstdc++
CMD ["./turnurile_hanoi"]