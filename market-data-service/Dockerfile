FROM gcc:13 AS build

WORKDIR /src

RUN apt-get update && apt-get install -y \
    cmake \
    make \
    g++ \
    && rm -rf /var/lib/apt/lists/*

COPY . .

RUN mkdir -p build
RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build

FROM debian:bookworm-slim

WORKDIR /app

COPY --from=build /src/build/market-data-service /app/market-data-service

ENTRYPOINT ["/app/market-data-service"]
