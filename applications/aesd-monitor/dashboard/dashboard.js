async function loadSystem()
{
    const response =
        await fetch('/api/system');

    const data =
        await response.json();

    document.getElementById('hostname').textContent =
        data.system.hostname;

    document.getElementById('cpu').textContent =
        data.metrics.cpu;

    document.getElementById('memory').textContent =
        data.metrics.memory;

    document.getElementById('disk').textContent =
        data.metrics.disk;

    document.getElementById('load').textContent =
        data.metrics.load;

    document.getElementById('uptime').textContent =
        data.metrics.uptime;
}

async function loadNetwork()
{
    const response =
        await fetch('/api/network');

    const data =
        await response.json();

    const wlan =
        data.network.wlan0;

    const eth =
        data.network.eth0;

    document.getElementById('wlan-status').textContent =
        wlan.status;

    document.getElementById('wlan-ip').textContent =
        wlan.ip;

    document.getElementById('wlan-rx').textContent =
        wlan.rx_bytes;

    document.getElementById('wlan-tx').textContent =
        wlan.tx_bytes;

    document.getElementById('eth-status').textContent =
        eth.status;

    document.getElementById('eth-ip').textContent =
        eth.ip;

    document.getElementById('eth-rx').textContent =
        eth.rx_bytes;

    document.getElementById('eth-tx').textContent =
        eth.tx_bytes;
}

function determineSeverity(alert)
{
    if (alert.includes("threshold exceeded"))
    {
        return "WARNING";
    }

    if (alert.includes("returned to normal"))
    {
        return "INFO";
    }

    return "CRITICAL";
}

async function loadAlerts()
{
    const response =
        await fetch('/api/alerts');

    const data =
        await response.json();

    const filter =
        document.getElementById(
            'severity-filter').value;

    const list =
        document.getElementById(
            'alert-list');

    list.innerHTML = '';

    data.alerts.forEach(alert =>
    {
        const severity =
            determineSeverity(alert);

        if (filter !== 'ALL' &&
            severity !== filter)
        {
            return;
        }

        const item =
            document.createElement('li');

        item.textContent =
            `[${severity}] ${alert}`;

        if (severity === 'WARNING')
        {
            item.className = 'warning';
        }
        else if (severity === 'CRITICAL')
        {
            item.className = 'critical';
        }
        else
        {
            item.className = 'info';
        }

        list.appendChild(item);
    });
}

async function refreshDashboard()
{
    await loadSystem();
    await loadNetwork();
    await loadAlerts();
}

document
    .getElementById('severity-filter')
    .addEventListener(
        'change',
        loadAlerts);

refreshDashboard();

setInterval(
    refreshDashboard,
    5000);
