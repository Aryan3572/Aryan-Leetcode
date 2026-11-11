/**
 * @param {number} cost1
 * @param {number} cost2
 * @param {number} costBoth
 * @param {number} need1
 * @param {number} need2
 * @return {number}
 */
var minimumCost = function(cost1, cost2, costBoth, need1, need2) {
    let totalCost = 0;

    if(cost1 + cost2 <= costBoth)
    {
        totalCost = cost1 * need1 + cost2 * need2;
    }
    else{
        let cnt_3 = Math.min(need1, need2);
        totalCost = cnt_3 * costBoth;

        need1 -= cnt_3;
        need2 -= cnt_3;

        if(need1 > 0)
        {
            totalCost += need1 * Math.min(cost1 , costBoth);
        }
        else if(need2 > 0)
        {
            totalCost += need2 * Math.min(cost2 , costBoth);
        }
    }
    return totalCost;
};