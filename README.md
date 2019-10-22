# netwhat

``netwhat`` is a MCQ, but nearly all questions are the same and I made 2 tools to help you resolve them.

## Usage

### ``ip_info.sh``

```bash
bash ip_info.sh 125.14.78.5 24 # or
bash ip_info.sh 125.14.78.5 255.255.255.0
```

Will output the following informations:

* The Mask
* The Host
* The IP without the host
* Amount of available addresses
* The IP range of the Host

## ``addresses_from_mask``

```bash
bash addresses_from_mask.sh 255.128.0.0 # or
bash addresses_from_mask.sh 9
```

Will output the number of available addresses.
