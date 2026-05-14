FROM gcc:13 AS build
WORKDIR /src
RUN apt-get update && apt-get install -y cmake make && rm -rf /var/lib/apt/lists/*
COPY . .
RUN cmake --preset release && cmake --build --preset release

FROM debian:bookworm-slim
WORKDIR /app
RUN useradd -r -u 10001 appuser
COPY --from=build /src/build/release/market-data-service /app/market-data-service
USER appuser
ENTRYPOINT ["/app/market-data-service"]
