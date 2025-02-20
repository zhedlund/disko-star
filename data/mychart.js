var x_graph = [];
var y_graph_amplitude = [];

var array_length = 100;
for (let i = 0; i < array_length; i++) {
    x_graph[i] = i;
    y_graph_amplitude[i] = 0;
}

const myChart = new Chart("myChart", {
    type: "line",
    data: {
        labels: x_graph,
        datasets: [
        {
            fill: false,
            lineTension: 0,
            data: y_graph_amplitude,
            backgroundColor: "#56006c",
            borderColor: "#56006c",
        }
    ],
    },
    options: {
        legend: { display: false },  // Set to true to differentiate the datasets
        scales: {
            yAxes: [{ ticks: { min: 0, max: 100 } ,
                display: false,
                scaleLabel: {
                    display: true,
                    labelString: '%',
                    fontSize: 20,
                }}],
                xAxes: [{
                    ticks: {
                        min: -1,
                        max: 100
                    },
                    display: false,
                    scaleLabel: {
                        display: true,
                        labelString: 'Time (seconds)'
                    }
                }]
        },
    },
});

function update_graph_amplitude(data) {
    console.log(data);
    myChart.data.datasets[0].data = data;
    myChart.update();
}