<script>
        function calculate() {
            const inputs = {
                in1: parseFloat(document.getElementById('in1').value),
                in2: parseFloat(document.getElementById('in2').value),
                in3: parseFloat(document.getElementById('in3').value),
                in4: parseFloat(document.getElementById('in4').value),
                in5: parseFloat(document.getElementById('in5').value),
                in6: parseFloat(document.getElementById('in6').value),
            };

            fetch('/calculate', {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify(inputs)
            })
            .then(response => response.json())
            .then(data => {
                document.getElementById('outputSection').style.display = 'flex';

                // Fill all outputs
                for (let i = 1; i <= 15; i++) {
                    document.getElementById('out' + i).innerText = data.outputs[i - 1].toFixed(3);
                }

                let capacity = data.outputs[1]; // Capacity (kW)
                document.getElementById('out2').innerText = capacity.toFixed(3) + " kW";

                // Adjust Capacity if Ambient Temperature is between -5 and 5
                if (inputs.in1 >= -5 && inputs.in1 <= 5) {
                    capacity -= 0.6;
                    document.getElementById('adjustmentNotice').style.display = 'block';
                } else {
                    document.getElementById('adjustmentNotice').style.display = 'none';
                }

                document.getElementById('finalCapacity').innerText = capacity.toFixed(3);
            });
        }
    </script>