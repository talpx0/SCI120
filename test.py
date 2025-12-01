import matplotlib.pyplot as plt

def plot_edgeworth_box_clean(
    total_food=10,
    total_clothing=6,
    A_food_A=7,
    A_cloth_A=1,
    B_food_A=6,
    B_cloth_A=2,
    shift_C=1,   # vertical shift in clothing for A, B, and the square
):
    fig, ax = plt.subplots(figsize=(10, 6))

    # Apply vertical shift to A and B
    A_cloth_shift = A_cloth_A + shift_C
    B_cloth_shift = B_cloth_A + shift_C

    # Edgeworth box
    ax.plot(
        [0, total_food, total_food, 0, 0],
        [0, 0, total_clothing, total_clothing, 0],
        linewidth=1.5,
        color="black",
    )

    # Points A and B
    ax.scatter(
        [A_food_A, B_food_A],
        [A_cloth_shift, B_cloth_shift],
        s=60,
        zorder=5,
        color="tab:blue",
    )
    ax.text(A_food_A + 0.1, A_cloth_shift - 0.25, "A", fontsize=12)
    ax.text(B_food_A + 0.1, B_cloth_shift + 0.1, "B", fontsize=12)

    # Dashed reference lines at the shifted levels
    for y in [A_cloth_shift, B_cloth_shift]:
        ax.hlines(y, 0, total_food,
                  linestyles="dashed", linewidth=0.8, color="gray")
    for x in [B_food_A, A_food_A]:
        ax.vlines(x, 0, total_clothing,
                  linestyles="dashed", linewidth=0.8, color="gray")

    # ----- NEW: arrows like the pink diagram -----
    arrow_color = "#ff4fb3"  # pink

    # corners of the small square
    bottom_left  = (B_food_A, A_cloth_shift)
    bottom_right = (A_food_A, A_cloth_shift)   # this is A
    top_left     = (B_food_A, B_cloth_shift)   # this is B
    top_right    = (A_food_A, B_cloth_shift)

    # bottom edge: A -> left
    ax.annotate(
        "",
        xy=bottom_left,
        xytext=bottom_right,
        arrowprops=dict(arrowstyle="->", linewidth=1.5, color=arrow_color),
    )

    # left edge: bottom_left -> B (up)
    ax.annotate(
        "",
        xy=top_left,
        xytext=bottom_left,
        arrowprops=dict(arrowstyle="->", linewidth=1.5, color=arrow_color),
    )

    # right edge: A -> top_right (up)
    ax.annotate(
        "",
        xy=top_right,
        xytext=bottom_right,
        arrowprops=dict(arrowstyle="->", linewidth=1.5, color=arrow_color),
    )

    # top edge: top_right -> B (left)
    ax.annotate(
        "",
        xy=top_left,
        xytext=top_right,
        arrowprops=dict(arrowstyle="->", linewidth=1.5, color=arrow_color),
    )
    # ----- end of arrow block -----

    # Labels for changes on right and bottom sides
    ax.text(
        A_food_A + 0.15,
        (A_cloth_shift + B_cloth_shift) / 2,
        "+1C",
        fontsize=11,
        color=arrow_color,
    )
    ax.text(
        (A_food_A + B_food_A) / 2 - 0.3,
        A_cloth_shift - 0.35,
        "-1F",
        fontsize=11,
        color=arrow_color,
    )

    # Person A's axes
    ax.set_xlim(0, total_food)
    ax.set_ylim(0, total_clothing)
    ax.set_xticks([0, B_food_A, A_food_A, total_food])
    ax.set_xticklabels(["0", f"{B_food_A}F", f"{A_food_A}F", f"{total_food}F"])
    ax.set_xlabel("Person A's Food →")

    ax.set_yticks([0, A_cloth_shift, B_cloth_shift, total_clothing])
    ax.set_yticklabels([
        "0",
        f"{A_cloth_shift}C",
        f"{B_cloth_shift}C",
        f"{total_clothing}C",
    ])
    ax.set_ylabel("→ Person A's Clothing")

    # Person B's axes (right & top)
    ax_top = ax.twiny()
    ax_top.set_xlim(ax.get_xlim())
    xticks = [0, B_food_A, A_food_A, total_food]
    ax_top.set_xticks(xticks)
    ax_top.set_xticklabels([f"{total_food - x}F" for x in xticks])
    ax_top.set_xlabel("← Person B's Food")

    ax_right = ax.twinx()
    ax_right.set_ylim(ax.get_ylim())
    yticks = [0, A_cloth_shift, B_cloth_shift, total_clothing]
    ax_right.set_yticks(yticks)
    ax_right.set_yticklabels(
        [f"{total_clothing - y}C" for y in yticks]
    )
    ax_right.set_ylabel("Person B's Clothing ←")

    # Direction arrows (unchanged)
    ax.annotate(
        "",
        xy=(total_food * 0.8, -0.3),
        xytext=(total_food * 0.2, -0.3),
        arrowprops=dict(arrowstyle="->", linewidth=1.2, color="black"),
    )
    ax.annotate(
        "",
        xy=(-0.4, total_clothing * 0.8),
        xytext=(-0.4, total_clothing * 0.2),
        arrowprops=dict(arrowstyle="->", linewidth=1.2, color="black"),
    )
    ax_top.annotate(
        "",
        xy=(total_food * 0.2, total_clothing + 0.35),
        xytext=(total_food * 0.8, total_clothing + 0.35),
        arrowprops=dict(arrowstyle="->", linewidth=1.2, color="black"),
    )
    ax_right.annotate(
        "",
        xy=(total_food + 0.4, total_clothing * 0.2),
        xytext=(total_food + 0.4, total_clothing * 0.8),
        arrowprops=dict(arrowstyle="<-", linewidth=1.2, color="black"),
    )

    plt.tight_layout()
    plt.show()

