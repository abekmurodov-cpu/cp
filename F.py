SECONDS_IN_DAY = 24 * 60 * 60


def to_seconds(date, time):
    month, day = map(int, date.split("."))
    hour, minute, second = map(int, time.split(":"))

    
    days_before_month = {
        6: 0,
        7: 30,
        8: 61,
        9: 92,
    }

    total_days = days_before_month[month] + day - 1
    return (
        total_days * SECONDS_IN_DAY
        + hour * 60 * 60
        + minute * 60
        + second
    )


def print_duration(activity, duration):
    days = duration // SECONDS_IN_DAY
    duration %= SECONDS_IN_DAY

    hours = duration // (60 * 60)
    duration %= 60 * 60

    minutes = duration // 60
    seconds = duration % 60

    print(f"{activity} {days} {hours:02d}:{minutes:02d}:{seconds:02d}")


n = int(input())

date, time, current_activity = input().split()
current_time = to_seconds(date, time)

total = {
    "S": 0,
    "W": 0,
    "T": 0,
    "R": 0,
}

for _ in range(n - 1):
    date, time, next_activity = input().split()
    next_time = to_seconds(date, time)

    total[current_activity] += next_time - current_time

    current_time = next_time
    current_activity = next_activity


summer_end = to_seconds("09.01", "00:00:00")
total[current_activity] += summer_end - current_time

print_duration("S", total["S"])
print_duration("W", total["W"])
print_duration("T", total["T"])
print_duration("R", total["R"])
