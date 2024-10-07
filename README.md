# Лабораторная работа №2

[![Maintainability](https://api.codeclimate.com/v1/badges/ef8e8197b17f1d13c7b6/maintainability)](https://codeclimate.com/github/Sherman-m/soft_dev_methods-lab02/maintainability)

## Описание:

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

Коды доступных игр:

- <b>LCM</b> (<b>L</b>east <b>C</b>ommon <b>M</b>ultiple) - найти наименьшее общее кратное 3-х
  чисел;

- <b>GEOMPROG</b> (<b>Geom</b>etry <b>Prog</b>ression) - найти пропущенный элемент
  геометрической прогрессии.

Для запуска опредленной игры необоходимо передать ее код в переменную `GAME_CODE=` во выполнения команды `make start-*`.<br> 
Например: запустить игру <b>LCM</b> можно командой `make start-release GAME_CODE=LCM`.

## Пример запуска:

Запуск игры <b>LCM</b> (<b>L</b>east <b>C</b>ommon <b>M</b>ultiple):

[![asciicast](https://asciinema.org/a/e369qTi8ZloEP9Jo3MdsJilg0.svg)](https://asciinema.org/a/e369qTi8ZloEP9Jo3MdsJilg0)


Запуск игры <b>GEOMPROG</b> (<b>Geom</b>etry <b>Prog</b>ression):

[![asciicast](https://asciinema.org/a/8yXG4rEJmdKEhiUQzFuxIlWmN.svg)](https://asciinema.org/a/8yXG4rEJmdKEhiUQzFuxIlWmN)


Сценарий игры с неправильным ответом:

[![asciicast](https://asciinema.org/a/oxaQQ0E0WFb7BWdmvk1MxZ848.svg)](https://asciinema.org/a/oxaQQ0E0WFb7BWdmvk1MxZ848)

