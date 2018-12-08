import subprocess

import matplotlib.pyplot as plt
import numpy as np
import seaborn as sb
from tqdm import tqdm

sb.set()
plt.rcParams['figure.figsize'] = [8, 4]
plt.rcParams['figure.dpi'] = 144
plt.rcParams['axes.unicode_minus'] = False
sb.set_style("ticks")


def run_test(cmd, arg):
    res = {"para": [], "ticks": []}
    for sarg in tqdm(arg):
        cmd_s = cmd.format(sarg)
        tmp = 0
        for _ in range(1):
            tmp += int(subprocess.check_output(cmd_s.split(" ")).decode("utf-8"))
        res["para"].append(sarg)
        res["ticks"].append(tmp / 1)
    res["para"] = np.array(res["para"])
    res["ticks"] = np.array(res["ticks"])
    return res


if __name__ == "__main__":
    markers = ['o', 'v', '8', 's', '*', 'h', 'H', 'D', 'd', 'P', 'X']
    i = 0
    # for n_size in tqdm(np.linspace(1000, 21000, 5).astype(np.int)):
    #     res = run_test("./a.o 0 {} {} 10000".format("{}", n_size),
    #                    np.linspace(2, 16, 15).astype(np.int))
    #     x = res["para"]
    #     # x = np.log(x)
    #     y = res["ticks"]
    #     plt.scatter(x, y, marker=markers[i],
    #                 s=20, label="para={}".format(n_size), c="black")
    #     i += 1
    #     i %= len(markers)
    #     plt.plot(res["para"], res["ticks"], c="black")
    res = run_test("./a.o 0 {} 1000 10000",
                   np.linspace(2, 32, 31).astype(np.int))
    x = res["para"]
    x = 1 / np.log(x)
    # x = (x - x.mean()) / x.var() ** 2
    y = res["ticks"]
    # y = np.exp(1 / y)
    # y = (y - y.min()) / (y.max() - y.min())
    # plt.scatter(x, y)
    plt.scatter(x, y, label="$T~1/lnB$", c="black", marker="^")
    A = np.vstack([x, np.ones(len(x))]).T
    m, c = np.linalg.lstsq(A, y, rcond=None)[0]
    plt.plot(x, m*x + c, c='black',
             label='$T={:.3f}/lnB + {:.3f}$'.format(m, c), linestyle="--")
    plt.legend()
    plt.savefig("output/result.png")
    # plt.show()
