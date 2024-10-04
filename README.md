# Лабораторная работа №2

## Сборка и запуск

Сборка и запуск приложения производится с использованием Makefile.

Основные команды:

| Команда | Описание |
|---------|----------|
| `make build-debug` | Сборка приложения в режиме Debug |
| `make build-release` | Сборка приложения в режиме Release | 
| `make start-debug GAME_CODE=<GAME_CODE>` | Запуск игры с соответствующим GAME_CODE в режиме Debug |
| `make start-release GAME_CODE=<GAME_CODE>` | Запуск игры с соответствующим GAME_CODE в режиме Release |
| `make check-lint` | Запуск линтеров для проверки кода (ничего не исправляют, только выводят предупреждения). Конфиги: [.clang-format](.clang-format) и [.clang-tidy](.clang-tidy) |
| `make lint` | Запуск линтеров для изменения кода. Конфиги: [.clang-format](.clang-format) и [.clang-tidy](.clang-tidy) |
| `make clean` | Удаление всех директорий сборки |
| `make codeclimate` | Запуск статического анализатора [Codeclimate CLI](https://github.com/codeclimate/codeclimate) |
